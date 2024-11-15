#include<bits/stdc++.h>


using namespace std;

class Car
{
public:
    string mBrand;
    string mLicensePlate;
    uint16_t mYearOfFabrication;
    double mAverageConsumption;
    uint32_t mNumberOfKilometers;

    Car(string marca, string nr_inmatr, uint16_t an, double cons_med, uint32_t km )
    {
        mBrand = marca;
        mLicensePlate = nr_inmatr;
        mYearOfFabrication = an;
        mAverageConsumption = cons_med;
        mNumberOfKilometers = km;
    }
    string getBrand()const
    {
        return mBrand;
    }
    string getLicensePlate()const
    {
        return mLicensePlate;
    }
    uint16_t getYearOfFabrication()const
    {
        return  mYearOfFabrication;
    }
    double getAverageConsumption()const
    {
        return mAverageConsumption;
    }
    uint32_t getNumberOfKilometers()const
    {
        return mNumberOfKilometers;
    }
    virtual double getFuelConsumption()const = 0;
    virtual double getFuelCost()const = 0;
    virtual string getType()const = 0;
    bool operator<(const Car &masina)
    {
        if(mYearOfFabrication > masina.mYearOfFabrication)
            return false;
        if(mYearOfFabrication == masina.mYearOfFabrication)
            if(mNumberOfKilometers > masina.mNumberOfKilometers)
                return false;
            else
                return true;
    }
};

class PetrolCar : public Car
{
public:
    PetrolCar(string marca, string nr_inmatr, uint16_t an, double cons_med, uint32_t km) : Car(marca, nr_inmatr, an, cons_med, km)
    {

    }
    double getFuelConsumption()const
    {
        return (0.879*mAverageConsumption*mNumberOfKilometers)/100;
    }
    double getFuelCost()const
    {
        return getFuelConsumption()*4.5;
    }
    string getType()const
    {
        return "benzina";
    }
};

class DieselCar : public Car
{
public:
    DieselCar(string marca, string nr_inmatr, uint16_t an, double cons_med, uint32_t km) : Car(marca, nr_inmatr, an, cons_med, km)
    {

    }
    double getFuelConsumption()const
    {
        return (0.789*mAverageConsumption*mNumberOfKilometers)/100;
    }
    double getFuelCost()const
    {
        return getFuelConsumption()*4.8;
    }
    string getType()const
    {
        return "diesel";
    }
};


class HybridCar : public Car
{
public:
    HybridCar(string marca, string nr_inmatr, uint16_t an, double cons_med, uint32_t km) : Car(marca, nr_inmatr, an, cons_med, km)
    {

    }
    double getFuelConsumption()const
    {
        return (mAverageConsumption*mNumberOfKilometers-0.124*mNumberOfKilometers)/100;
    }
    double getFuelCost()const
    {
        return getFuelConsumption()*4.5;
    }
    string getType()const
    {
        return "hibrid";
    }
};


class ElectricCar : public Car
{
public:
    ElectricCar(string marca, string nr_inmatr, uint16_t an, double cons_med, uint32_t km) : Car(marca, nr_inmatr, an, cons_med, km)
    {

    }
    double getFuelConsumption()const
    {
        return 0;
    }
    double getFuelCost()const
    {
        return 0;
    }
    string getType()const
    {
        return "electrica";
    }
};

static bool sortare(Car * a, Car * b)
{
    if(a->getYearOfFabrication() > b->getYearOfFabrication())
        return true;
    if(a->getYearOfFabrication() == b->getYearOfFabrication())
    {
        if(a-> getNumberOfKilometers() < b-> getNumberOfKilometers())
            return true;
        if(a-> getNumberOfKilometers() == b-> getNumberOfKilometers())
        {
            if(a->getAverageConsumption() > b->getAverageConsumption())
                return true;
        }
    }
    return false;
}

int main()
{
    vector <Car*> masini;
    string v[1000];
    string marca, nr, tip, pct;
    uint16_t an;
    uint32_t km;
    double cons_med,mediu=0, j=0,consum;
    int n, k=0,b=0,d=0,h=0,e=0,nr_km=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> marca >> tip >> nr >> an >> cons_med >> km;
        v[k]=tip;
        k++;
        j++;
        nr_km=nr_km+km;
        mediu=mediu+cons_med;
        if(tip=="benzina")
        {
            masini.push_back(new PetrolCar(marca,nr, an, cons_med, km));
        }
        if(tip=="diesel")
        {
            masini.push_back(new DieselCar(marca,nr, an, cons_med, km));
        }
        if(tip=="hibrid")
        {
            masini.push_back(new HybridCar(marca,nr, an, cons_med, km));
        }
        if(tip=="electrica")
        {
            masini.push_back(new ElectricCar(marca,nr, an, cons_med, km));
        }

    }
    cin >> pct;
    if(pct == "a")
    {
        sort(masini.begin(), masini.end(),sortare);
        for(int i=0;i<masini.size();i++)
        {

            cout <<"Masina "<<masini[i]->getBrand()<<" cu numarul de inmatriculare "<<masini[i]->getLicensePlate()<<" a parcurs "<<masini[i]->getNumberOfKilometers()<<"km si a consumat "<<fixed<<setprecision(3)<<masini[i]->getFuelConsumption()<<" litri."<<'\n';
        }
    }
    if(pct == "b")
    {
        j=0;
        for(int i=0;i<masini.size();i++)
        {
            j=j+masini[i]->getFuelCost();
        }
        cout<<j<<'\n';
    }
    if(pct == "c")
    {
        while(cin >> marca >> tip >> nr >> an >> cons_med >> km)
        {
            j++;
            nr_km=nr_km+km;
            mediu=mediu+cons_med;

        }
        cout << nr_km << " km" <<'\n';
        cout<< fixed << setprecision(2)<< mediu/j << fixed << setprecision(2)<< " L/100km" << '\n';
    }
    if(pct == "d")
    {
        for(int i=0;i<k;i++)
        {
            if(v[i]=="benzina")
                b++;
            if(v[i]=="diesel")
                d++;
            if(v[i]=="hibrid")
                h++;
            if(v[i]=="electrica")
                e++;
        }
        cout << "benzina -> " << b << '\n';
        cout << "diesel -> " << d << '\n';
        cout << "electrica-> " << e << '\n';
        cout << "hibrid -> " << h << '\n';
    }
    if(pct == "e")
    {
        for(int i=0;i<masini.size();i++)
        {
            string s = masini[i]->getLicensePlate();
            j=s.size();
            if(j>8)
            {
                cout<<masini[i]->getLicensePlate()<<": numar de inmatriculare invalid"<<'\n';
            }
            if(s[j-1] == 48)
                cout<<masini[i]->getLicensePlate()<<": numar de inmatriculare invalid"<<'\n';
            if(s[2]>=48 &&s[2]<=57 && s[3]>=65 && s[3]<=90)
            {
                if(s[6]>=65 && s[6]<=90)
                    cout<<masini[i]->getLicensePlate()<<": numar de inmatriculare invalid"<<'\n';
            }
            if(s[2]>=65 && s[2]<=90)
                cout<<masini[i]->getLicensePlate()<<": numar de inmatriculare invalid"<<'\n';

        }
    }
    return 0;
}