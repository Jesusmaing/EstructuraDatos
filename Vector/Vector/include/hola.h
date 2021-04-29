#ifndef HOLA_H
#define HOLA_H


class hola
{
    public:
        hola(martin);
        virtual ~hola();

        unsigned int Getm_Counter() { return m_Counter; }
        void Setm_Counter(unsigned int val) { m_Counter = val; }
         int Get() { return m_si; }
        void Set( int val) { m_si = val; }

    protected:

    private:
        unsigned int m_Counter;
         int m_si;
};

#endif // HOLA_H
