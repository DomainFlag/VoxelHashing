#pragma once

/************************************************************************/
/* Kinect Sensor (the old version of a Kinect)                          */
/************************************************************************/

#include "GlobalAppState.h"

#ifdef KINECT

#include "RGBDSensor.h"
#include <NuiApi.h>
#include <NuiSkeleton.h>

#include <ATen/cuda/CUDAContext.h>
#include <ATen/ATen.h>

#include <cuda.h>
#include <cuda_runtime.h>

#include "torch/script.h"

class KinectSensor : public RGBDSensor
{
public:
	KinectSensor();
	//! Constructor; allocates CPU memory and creates handles

	//! Destructor; releases allocated ressources
	~KinectSensor();

	//! Initializes the sensor
	HRESULT createFirstConnected();

	//! gets the next depth frame
	HRESULT processDepth();

	//! maps the color to depth data and copies depth and color data to the GPU
	HRESULT processColor();

	std::string getSensorName() const {
		return "Kinect";
	}

	//! toggles near mode if possible (only available on a windows Kinect)
	HRESULT toggleNearMode();

	//! Toggle enable auto white balance
	HRESULT toggleAutoWhiteBalance();

	//! Compute mask for person scanning

	void KinectSensor::processMask();

	//! Benchmark helper for computing the mask 
	static void KinectSensor::benchmarkMask(torch::jit::script::Module & model);

private:
	INuiSensor*		m_pNuiSensor;

	torch::jit::script::Module module;
	torch::Device device = torch::kCPU;

	std::vector<float> mean = { 0.485, 0.456, 0.406 };
	std::vector<float> sd = { 0.229, 0.224, 0.225 };
	std::vector<std::string> labels = { "__background__", "aeroplane", "bicycle", "bird", "boat", "bottle", "bus",
		"car", "cat", "chair", "cow", "diningtable", "dog", "horse", "motorbike",
		"person", "pottedplant", "sheep", "sofa", "train", "tvmonitor" };

	float sensibility = 9.0f;
	int target = -1;

	static const NUI_IMAGE_RESOLUTION   cDepthResolution = NUI_IMAGE_RESOLUTION_640x480;
	static const NUI_IMAGE_RESOLUTION   cColorResolution = NUI_IMAGE_RESOLUTION_640x480;

	HANDLE			m_hNextDepthFrameEvent;
	HANDLE			m_pDepthStreamHandle;
	HANDLE			m_hNextColorFrameEvent;
	HANDLE			m_pColorStreamHandle;

	LONG*			m_colorCoordinates;		// for mapping depth to color

	LONG			m_colorToDepthDivisor;

	bool			m_bDepthImageIsUpdated;
	bool			m_bDepthImageCameraIsUpdated;
	bool			m_bNormalImageCameraIsUpdated;

	bool			m_kinect4Windows;
	bool			m_bNearMode;

};
#endif