
from math import pi


def angle_power_system(teta0,tetaf,radians = True):
    """ Renvoie le delta angulaire relatif à exercer pour une consigne angulaire absolue 
    mettre radians = False pour fonctionner en degré 
    Tout les angles sont dans ]-pi;pi] (ou 180)"""
    convert = 180
    if radians:
       convert = pi     
    delta_cons = (teta0-tetaf)*(2*(abs(teta0-tetaf)>convert)-1) + convert*(2*(teta0<tetaf)-1)*(abs(teta0-tetaf)>convert)
    print(f"\n\tPour teta0 = {teta0}° et tetaf = {tetaf}° on a delta = {delta_cons}°")
    return
 
