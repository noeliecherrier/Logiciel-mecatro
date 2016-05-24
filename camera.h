
#ifndef CAMERAPIKE_H
#define CAMERAPIKE_H

#include "Vimba_2.0/VimbaCPP/Include/VimbaCPP.h"
#include "Vimba_2.0/VimbaC/Include/VimbaC.h"
#include "ApiController.h"

using AVT::VmbAPI::Examples::ApiController;

class CameraPike : public AVT::VmbAPI::Camera
{
public:
	CameraPike();
	~CameraPike();

	// Basic features
	std::string getName();
	int* getSensorSize(); // array 0 : width, 1 : height (pixels)
	int* getPictureSize(); // idem
	std::string getPixelFormat();

	// Operations on image
	bool reverseX(); // sym�trise horizontalement l'image envoy�e par la cam�ra
	bool reverseY(); // idem mais verticalement
	bool setPixelColorFilter_auto(); // filtre couleur automatique (aucun ?)
	std::string getPixelColorFilter(); // r�cup�rer le type de filtre couleur appliqu�
	bool setPixelColorFilter(char *mode); // variables possibles : BayerRG BayerGB BayerGR BayerBG

	// Acquisition control
	int getExposureTime();
	bool setExposureTime(int time_us);

	// Picture commands
	// Appeler au d�but et � la fin du process entier
	bool start_acquisition();
	bool stop_acquisition();

	// Prendre une image (� mettre plusieurs fois au cours du process)
	AVT::VmbAPI::FramePtr take_picture();

	AVT::VmbAPI::IFrameObserverPtr start_getting_images();
	bool stop_getting_images();
	void get_image(AVT::VmbAPI::IFrameObserverPtr frameObserver); // en continu, �v�nement nouvelle frame => actualisation de l'affichage

private:
	// Our controller that wraps API access
	ApiController *             m_pApiController;
	// A list of known camera IDs
	std::vector<std::string>    m_cameras;
	// Are we streaming?
	bool                        m_bIsStreaming;

};

#endif // CAMERAPIKE_H



// AVT::VmbAPI::FramePtr