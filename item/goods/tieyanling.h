//tieyanling.h
//Lanwood
//2001-01-09

ITEM_BEGIN(CItieyanling)

virtual void create(int nFlag = 0)		
{
	set_name("铁焰令", "tieyan ling");
    set_weight(500);
        
    set("unit", "面");
    set("long","这是一面黑黝黝的令牌，由教主签发，凭此可向尊长挑战。");
    set("material", "steel");
};

ITEM_END;
