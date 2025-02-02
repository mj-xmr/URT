//=================================================================================================
//                    Copyright (C) 2016 Olivier Mallet - All Rights Reserved
//=================================================================================================

#ifndef COEFF_ADF_HPP
#define COEFF_ADF_HPP

// critical values response surface coefficients
// for each probability or significance level the associated quantile is estimated via the following regression:
// C(k,T)(p) = B0 + B1/T + B2/T^2 + B3*(k/T) + B4*(k/T)^2 + e(k,T)
// with T = N - k - 1 where N is the sample size, k is the number of lags, T is the effective number of observations and e(k,T) the residuals
// B0 is the asymptotic critical value of the test for the p significance level
// this is an example, in some cases we will have more term in 1/T^i or (k/T)^i
// in the example above, index 0 would contain B0, B1 and B2 and index 1 B3 and B4
// The choice of the number of regressors has been made looking at the precision of each model estimation by comparing with Monte-Carlo simulated critical values, and taking into account the regression quality that is the parameters heteroskedasticity consistent standard errors and t values, the regression standard error, the Akaike information criterion, the goodness of fit R and the residuals auto-correlation.
// We have taken care especially of the quality of the 1%, 5% and 10% confidence levels regressions.

// We have used the methodology explained in "Lag Order and Critical Values of the Augmented Dickey-Fuller Test" by Cheung and Lai (1995), we have extended the sample sizes and number of lags and have used more replications to get more accurate results.

#include <map>
#include <vector>
#include <string>

static const std::map<std::string,std::map<float,std::map<int,std::vector<float>>>> coeff_adf =
{
    {"nc",{
        {0.001,{
            {0, {-3.281702, -4.768726, -272.9072, 5579.295, -45226.96}},
            {1, {0.5493214, -2.698764}}}},
        {0.005,{
            {0, {-2.794503, -3.1995, -146.9075, 3099.156, -24497.04}},
            {1, {0.5505589, -2.085242}}}},
        {0.01,{
            {0, {-2.561287, -2.142564, -121.1985, 2584.976, -20410.33}},
            {1, {0.4760427, -1.539142}}}},
        {0.025,{
            {0, {-2.223917, -0.6914316, -111.5947, 2411.508, -17908.34}},
            {1, {0.4181673, -1.186685}}}},
        {0.05,{
            {0, {-1.936403, -1.176172, -4.937049}},
            {1, {0.4133739, -1.106667}}}},
        {0.10,{
            {0, {-1.61316, -0.3324831, -1.810886}},
            {1, {0.346874, -0.7603873}}}},
        {0.20,{
            {0, {-1.232539, 0.6746855, -2.034739}},
            {1, {0.2687615, -0.4501587}}}},
        {0.50,{
            {0, {-0.5019654, 4.022296, -26.36976}},
            {1, {0.2869943, 0.03450908}}}},
        {0.8,{
            {0, {0.4032327, 4.540675, -33.07985}},
            {1, {0.5776706, 0.2456931}}}},
        {0.9,{
            {0, {0.8867146, 4.419886, -29.49461}},
            {1, {0.741675, -0.1049857}}}},
        {0.95,{
            {0, {1.281964, 4.550459, -25.75607}},
            {1, {0.8509155, -0.4257711}}}},
        {0.975,{
            {0, {1.621407, 4.919284, -21.08875}},
            {1, {0.9096531, -0.6824688}}}},
        {0.99,{
            {0, {2.013246, 5.729489, -14.25646}},
            {1, {0.9222194, -0.6803509}}}},
        {0.995,{
            {0, {2.278707, 6.459439, -6.844265}},
            {1, {0.9229393, -0.58905}}}},
        {0.999,{
            {0, {2.82238, 8.798691, 15.4077}},
            {1, {0.8097516, 0.076346}}}}
        }},
    {"c",{
        {0.001,{
            {0, {-4.093629, -10.95619, -201.1707, 4059.445, -47421.5}},
            {1, {1.135068, -5.529418}}}},
        {0.005,{
            {0, {-3.644943, -7.32321, -133.5845, 3116.307, -34229.66}},
            {1, {0.9485738, -3.219351}}}},
        {0.01,{
            {0, {-3.431418, -5.638492, -117.5981, 2807.583, -28966.07}},
            {1, {0.8777557, -2.478217}}}},
        {0.025,{
            {0, {-3.122512, -4.084893, -56.41564, 1374.696, -15404.28}},
            {1, {0.7851985, -1.540707}}}},
        {0.05,{
            {0, {-2.861234, -3.352301, 14.44003, -393.0152}},
            {1, {0.7401921, -1.162586}}}},
        {0.1,{
            {0, {-2.56724, -1.456952, -11.77928}},
            {1, {0.6391723, -0.5805052}}}},
        {0.2,{
            {0, {-2.21775, -0.4380315, -5.553964}},
            {1, {0.5146035, 0.07913832}}}},
        {0.5,{
            {0, {-1.565026, 0.5520032, 0.3320911}},
            {1, {0.2884884, 1.558016}}}},
        {0.8,{
            {0, {-0.8648469, 1.248728, 0.2664044}},
            {1, {1.179858, 1.250165}}}},
        {0.9,{
            {0, {-0.4406348, 1.649804, -3.58948}},
            {1, {1.939274, 0.2523149}}}},
        {0.95,{
            {0, {-0.07812974, 1.893762, -6.304656}},
            {1, {2.639824, -0.7719409}}}},
        {0.975,{
            {0, {0.239394, 2.14986, -8.572655}},
            {1, {3.330538, -1.912599}}}},
        {0.99,{
            {0, {0.6091726, 2.496982, -7.439446}},
            {1, {4.225463, -3.616533}}}},
        {0.995,{
            {0, {0.8623198, 2.874015, -5.580965}},
            {1, {4.839039, -4.653141}}}},
        {0.999,{
            {0, {1.38689, 3.415222, 13.42629}},
            {1, {6.166719, -6.678131}}}}
        }},
    {"ct",{
        {0.001,{
            {0, {-4.602904, -12.17787, -527.9003, 13769.63, -149247.9}},
            {1, {1.738192, -8.439729}}}},
        {0.005,{
            {0, {-4.168873, -9.095683, -266.1883, 6786.044, -75171.46}},
            {1, {1.449617, -4.963447}}}},
        {0.01,{
            {0, {-3.961001, -7.941104, -164.6046, 4154.17, -48022.67}},
            {1, {1.33377, -3.942321}}}},
        {0.025,{
            {0, {-3.662298, -5.911063, -88.6424, 2221.722, -26744.54}},
            {1, {1.16549, -2.516979}}}},
        {0.05,{
            {0, {-3.410894, -4.149194, -64.03544, 1624.534, -18656.29}},
            {1, {1.022964, -1.462953}}}},
        {0.1,{
            {0, {-3.127902, -2.344014, -22.26126}},
            {1, {0.8885139, -0.7515388}}}},
        {0.2,{
            {0, {-2.7924, -0.9703418, -9.753819}},
            {1, {0.6833622, 0.4110066}}}},
        {0.5,{
            {0, {-2.17854, 0.6154379, 2.143893}},
            {1, {0.323513, 2.654173}}}},
        {0.8,{
            {0, {-1.584759, 1.35046, 9.264756}},
            {1, {0.8602757, 4.07367}}}},
        {0.9,{
            {0, {-1.250804, 2.20269, 4.417211}},
            {1, {1.987795, 2.371877}}}},
        {0.95,{
            {0, {-0.9430168, 2.91489, -3.161068}},
            {1, {2.961466, 0.795468}}}},
        {0.975,{
            {0, {-0.6617862, 3.388312, -7.564776}},
            {1, {3.852376, -0.7378108}}}},
        {0.99,{
            {0, {-0.3247998, 3.833996, -9.750533}},
            {1, {4.934732, -2.514723}}}},
        {0.995,{
            {0, {-0.09078475, 3.95775, -6.916539}},
            {1, {5.73554, -3.762424}}}},
        {0.999,{
            {0, {0.3995264, 4.650644, -2.198471}},
            {1, {7.366291, -5.53531}}}}
        }},
    {"ctt",{
        {0.001,{
            {0, {-5.013231, -12.32148, -931.3062, 26178.47, -281197.4}},
            {1, {2.373687, -13.23884}}}},
        {0.005,{
            {0, {-4.579845, -10.82918, -406.3291, 10976.8, -123523.2}},
            {1, {1.821085, -7.467968}}}},
        {0.01,{
            {0, {-4.376393, -9.20233, -288.6418, 7529.634, -84447.02}},
            {1, {1.637286, -5.610608}}}},
        {0.025,{
            {0, {-4.082349, -7.139103, -167.3334, 4387.772, -50031.24}},
            {1, {1.43226, -3.575693}}}},
        {0.05,{
            {0, {-3.833339, -5.531, -87.00663, 2242.58, -27241.12}},
            {1, {1.226892, -2.0091}}}},
        {0.1,{
            {0, {-3.551958, -4.452909, 26.14951, -675.7979}},
            {1, {1.021034, -0.6615268}}}},
        {0.2,{
            {0, {-3.223184, -1.522704, -13.55332}},
            {1, {0.77266, 0.8243226}}}},
        {0.5,{
            {0, {-2.617229, 0.5046602, 7.156626}},
            {1, {0.3347223, 3.860026}}}},
        {0.8,{
            {0, {-2.043999, 1.426968, 20.87687}},
            {1, {0.7072516, 6.213741}}}},
        {0.9,{
            {0, {-1.743752, 2.260416, 20.26852}},
            {1, {1.886585, 4.803952}}}},
        {0.95,{
            {0, {-1.474189, 3.330163, 11.66451}},
            {1, {3.088977, 2.70093}}}},
        {0.975,{
            {0, {-1.219848, 4.087149, 4.610631}},
            {1, {4.181104, 0.7281762}}}},
        {0.99,{
            {0, {-0.908479, 4.874732, -3.408405}},
            {1, {5.469988, -1.455318}}}},
        {0.995,{
            {0, {-0.6891048, 5.363189, -7.792514}},
            {1, {6.365469, -2.765692}}}},
        {0.999,{
            {0, {-0.2228572, 5.742693, -1.09101}},
            {1, {8.303857, -5.030229}}}}
        }}
};

#endif
