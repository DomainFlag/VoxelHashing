The forked repo adds the option to perform segmentation in order to perform selective registration of specific entities such as people while applying a mask to everything else.

The segmentation is done by using a pre-trained resnet101 model fine-tuned on COCO dataset. Download the LibTorch > C++/Java > CUDA (preferred) / CPU https://pytorch.org/get-started/locally/ and set the corresponding `TORCH_DIR` to the library path.

For the model, download it from https://drive.google.com/open?id=11vPQNKJ0hYeGFlZLeNUinF67XQl_t5Bs and insert into (e.g) DepthSensingCUDA/Models/model_traceable.pt.

Running on VC++ 2017 v141 toolset with CUDA toolkit 10.2. Install .NET Framework 3.5 if it's not yet installed. Install the CUDA toolkit and move to CUDA toolkit installation path and copy the files from the MSBuildExtensions to MSBuild\Microsoft > ... > BuildCustomizations where the installation of VS is located. Configure accordingly the .vcxproj file elements and set up the versions for .props and .targets of the CUDA that you've copied.

You are free to use this code with proper attribution in non-commercial applications (Please see License.txt).
We are also happy to allow free commercial use; however, in that case we would like you to conact us first.
For use in a publication or presentation, please cite the VoxelHashing publication(s).

INSTALLATION:
The code was developed under VS2012.

CONTACT (feel free to contact us):
niessner@cs.stanford.edu
michael.zollhoefer@cs.fau.de

Requirements:
- DirectX SDK June 2010 - Make sure no Microsoft Visual C++ 2010 in installed prior to the installation.
- Kinect SDK (prev. to 2.0)
- NVIDIA CUDA 6.5 (for the CUDA implementation)

Optional:
- Kinect SDK (2.0 and above)
- Prime sense SDK

We are also looking for active participation in this open source effort making large-scale 3D scanning publically accessible. Please contact us :)
