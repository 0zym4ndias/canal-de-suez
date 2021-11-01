for (int i = index; i < 12; i++)
        {
            //cout << mes << endl;
            alerta2 = 0;
            if (mes != meses[i])
            {

                logRegistro.mes = meses[i];
                logRegistro.year = curr1->getData().year;
                logRegistro.cantMed = 0;
                logRegistro.cantRoj = 0;
                vectorF.push_back(logRegistro);

                //mes2 = curr1->getData().mes;
            }
            else
            {
                while (ubi3 == ubi && alerta2 == 0)
                {
                    if (mes == curr1->getData().mes)
                    {
                        alerta++;
                        if (curr1->getData().entrada == 'M')
                        {
                            cantM++;
                        }
                        else
                        {
                            cantR++;
                        }
                        if (alerta == 1)
                        {
                            logRegistro.mes = curr1->getData().mes;
                            logRegistro.year = curr1->getData().year;
                        }
                        logRegistro.cantMed = cantM;
                        logRegistro.cantRoj = cantR;
                        if (mes != curr1->getNext()->getData().mes)
                        {
                            vectorF.push_back(logRegistro);
                        }
                        //else
                        curr1 = curr1->getNext();
                        ubi3 = curr1->getData().ubi.substr(0, 3);
                    }
                    else
                    {
                        //vectorF.push_back(logRegistro);
                        alerta = 0;
                        cantM = 0;
                        cantR = 0;
                        mes = curr1->getData().mes;
                        alerta2 = 1;
                    }
                }
            }
        }
    }
    return vectorF;
}