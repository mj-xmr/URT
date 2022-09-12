#ifndef URTMIN_HPP_INCLUDED
#define URTMIN_HPP_INCLUDED


//=================================================================================================

#ifdef USE_BLAZE

  // neutralizing OpenMP in Blaze if defined
  #ifdef _OPENMP
    #undef _OPENMP
    #define SET_OPENMP_BACK
  #endif

  #ifndef NDEBUG
    #define NDEBUG
  #endif

  #if defined(USE_MKL) || defined (USE_BLAS)
    #define BLAZE_BLAS_MODE 1
    #define BLAZE_USE_BLAS_MATRIX_VECTOR_MULTIPLICATION 1
    #define BLAZE_USE_BLAS_MATRIX_MATRIX_MULTIPLICATION 1
  #endif

  #ifndef BLAZE_BLAS_INCLUDE_FILE
    #ifdef USE_MKL
      #define BLAZE_BLAS_INCLUDE_FILE <mkl_cblas.h>
    #elif USE_BLAS
      #define BLAZE_BLAS_INCLUDE_FILE <cblas.h>
    #endif
  #endif

  #include <blaze/math/DynamicVector.h>
  #include <blaze/math/DynamicMatrix.h>
  #include <blaze/math/CustomVector.h>
  #include <blaze/math/CustomMatrix.h>

  namespace urt {
     template <typename T>
     using Matrix = blaze::DynamicMatrix<T, blaze::columnMajor>;
     template <typename T>
     using CMatrix = blaze::CustomMatrix<T, blaze::unaligned, blaze::unpadded, blaze::columnMajor>;
     template <typename T>
     using Vector = blaze::DynamicVector<T>;
     template <typename T>
     using CVector = blaze::CustomVector<T, blaze::unaligned, blaze::unpadded>;
  }

  #ifdef SET_OPENMP_BACK
    #define _OPENMP
  #endif

//*************************************************************************************************

#elif USE_EIGEN

  #ifdef USE_MKL
    #define EIGEN_USE_MKL_ALL
  #elif USE_BLAS
    #define EIGEN_USE_BLAS
  #endif

  #define EIGEN_DONT_PARALLELIZE
  #define EIGEN_NO_DEBUG
  #define EIGEN_NO_STATIC_ASSERT

  #include <Eigen/Dense>

  namespace urt {
     template <typename T>
     using Matrix = Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>;
     template <typename T>
     using Vector = Eigen::Matrix<T, Eigen::Dynamic, 1>;
 }

//*************************************************************************************************

#else

  #ifndef ARMA_DONT_USE_WRAPPER
    #if defined(USE_MKL) || defined (USE_BLAS)
      #define ARMA_DONT_USE_WRAPPER
    #endif
  #endif

  #ifndef ARMA_NO_DEBUG
    #define ARMA_NO_DEBUG
  #endif

  #ifndef ARMA_USE_CXX11
    #define ARMA_USE_CXX11
  #endif

  #include <armadillo>

  namespace urt {
     template <typename T>
     using Matrix = arma::Mat<T>;
     template <typename T>
     using Vector = arma::Col<T>;
  }

#endif


#endif // URTMIN_HPP_INCLUDED
