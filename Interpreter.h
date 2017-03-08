class BooleanExpression
{
public:
    BooleanExpression(void);
    virtual ~BooleanExpression(void);

    virtual bool Evaluate(Context&) = 0;
};
