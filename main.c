#include <stdio.h>
#include <stdlib.h>
#include "BildschirmRoutinen.h"
void PunktZS(int iZeile, int iSpalte, char cZeichen, int idelay)
{
    GotoZS(iZeile, iSpalte);
    printf("%c", cZeichen);
    Delay(idelay);
    GotoZS(iZeile, iSpalte);
    printf(" ");


}
void Fliegendesteil(int iZeileOben, int iSpalteLinks, int iZeileUnten, int iSpalteRechts, char cZeichen, int idelay)
{
    int iZeile=(iZeileOben+iZeileUnten)/2;
    int iSpalte=(iSpalteLinks+iSpalteRechts)/2;
    int iNeueSpalte;
    int iNeueZeile;
    int iRichtungSpalte=1;
    int iRichtungZeile = -1;
    for (;;)
    {
        iNeueZeile=iZeile+iRichtungZeile;
        iNeueSpalte=iSpalte+iRichtungSpalte;
        if ((iZeileOben<iNeueZeile) && (iNeueZeile<iZeileUnten))
        {
            iZeile=iNeueZeile;
        }
        else
        {
            iRichtungZeile=-iRichtungZeile;
        }

        if ((iSpalteLinks<iNeueSpalte) && (iNeueSpalte<iSpalteRechts))
        {
            // im erlaubten Bereich
            iSpalte=iNeueSpalte;
        }
        else
        {
            // nicht im erlaubten Bereich
            iRichtungSpalte=-iRichtungSpalte;
        }
        PunktZS(iZeile, iSpalte, cZeichen, idelay);
    }
}
int main()
{
    Fliegendesteil(3, 3, 20, 60, "+", 50);
    return 0;
}
