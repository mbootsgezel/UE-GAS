


#include "MyPlayerController.h"

void AMyPlayerController::SetMousePosition(float LocationX, float LocationY)
{
	FViewport* v = CastChecked<ULocalPlayer>(this->Player)->ViewportClient->Viewport;
	int intX = (int)LocationX;
	int intY = (int)LocationY;
	v->SetMouse(intX, intY);
}
