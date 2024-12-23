//tuijianxin_2.h 推荐信 门-旗

ITEM_BEGIN(CItuijianxin_2)

virtual void create(int nFlag = 0)		
{
	set_name("推荐信", "tuijian xin2");
    set_weight(100);
    set("unit", "封");
    set("long","这是一封门主为你写的推荐信，凭此可去见五行旗掌旗使。");
    set("material", "paper");
};

ITEM_END;
