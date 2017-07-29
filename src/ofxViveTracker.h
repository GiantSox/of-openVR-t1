#pragma once
#include "ofMain.h"
#include "openvr.h"

class ofxViveTracker
{
private:
public:
	vr::IVRSystem *vrsys = NULL;
	ofPoint trackerPos;

	//Use vr::VRApplication_Other or vr::VRApplication_Utility if HMD not present
	void setup(vr::EVRApplicationType appType = vr::VRApplication_Background)
	{
		vr::EVRInitError initError = vr::VRInitError_None;
		vrsys = vr::VR_Init(&initError, appType);
		if (initError != vr::VRInitError_None)
		{
			vrsys = NULL;
			ofLogError("Could not initialize OpenVR (" + std::to_string(initError) + ")!");

		}
	}
	void update()
	{
		//Iterate through every SteamVR device
		for (vr::TrackedDeviceIndex_t unDevice = 0; unDevice < vr::k_unMaxTrackedDeviceCount; unDevice++)
		{
			//skip to next device if current one isn't connected
			if (!vrsys->IsTrackedDeviceConnected(unDevice))
				continue;

			vr::ETrackedDeviceClass trackedDeviceClass = vrsys->GetTrackedDeviceClass(unDevice);

			switch (trackedDeviceClass)
			{

			case vr::ETrackedDeviceClass::TrackedDeviceClass_GenericTracker:
				/*vr::VRControllerState_t controllerState;
				vr::TrackedDevicePose_t controllerPose;

				//prediction may be desirable
				//vrsys->GetDeviceToAbsoluteTrackingPose(vr::TrackingUniverseStanding, 0, &controllerPose, unDevice);
				vrsys->GetControllerStateWithPose(vr::TrackingUniverseStanding, unDevice, &controllerState, sizeof(controllerState), &controllerPose);
				vr::HmdMatrix34_t posMat = controllerPose.mDeviceToAbsoluteTracking;
				trackerPos.x = posMat.m[0][3];
				trackerPos.y = posMat.m[1][3];
				trackerPos.z = posMat.m[2][3];
				//cout << "Vive Tracker: " << trackerPos << endl;*/
				break;

			case vr::ETrackedDeviceClass::TrackedDeviceClass_Controller:

				switch (vrsys->GetControllerRoleForTrackedDeviceIndex(unDevice))
				{
				case vr::ETrackedControllerRole::TrackedControllerRole_LeftHand:
					cout << "Left Controller Connected" << endl;
					break;
				case vr::ETrackedControllerRole::TrackedControllerRole_RightHand:
					cout << "Right Controller Connected" << endl;
					vr::VRControllerState_t controllerState;
					vr::TrackedDevicePose_t controllerPose;

					//prediction may be desirable
					//vrsys->GetDeviceToAbsoluteTrackingPose(vr::TrackingUniverseStanding, 0, &controllerPose, unDevice);
					vrsys->GetControllerStateWithPose(vr::TrackingUniverseStanding, unDevice, &controllerState, sizeof(controllerState), &controllerPose);
					vr::HmdMatrix34_t posMat = controllerPose.mDeviceToAbsoluteTracking;
					trackerPos.x = posMat.m[0][3];
					trackerPos.y = posMat.m[1][3];
					trackerPos.z = posMat.m[2][3];
					//cout << "Vive Tracker: " << trackerPos << endl;


					vr::TrackedDevicePose_t poses[vr::k_unMaxTrackedDeviceCount];
					//use ofGetLastFrametime() to predict when frame presented
					vrsys->GetDeviceToAbsoluteTrackingPose(vr::TrackingUniverseStanding, 0, poses, vr::k_unMaxTrackedDeviceCount);
					break;
				default:
					break;
				}

			default:
				break;

			}

		}
	}
	void ProcessEvent(vr::VREvent_t &event);
	
	//void GetTrackingData()
};