#ifndef POSITION_H
#define POSITION_H


class position
{
    public:
        position();
        position(const position&);
        virtual ~position();

        int x = 0;
        int y = 0;


    protected:

    private:
};

#endif // POSITION_H
