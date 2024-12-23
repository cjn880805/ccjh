//chunjie_ld.h 礼单碎片
//秦波 2002-03-26

ITEM_BEGIN(CIchunjie_ld);

virtual void create(int nFlag = 0)	
{
	set_name("礼单碎片","li dan");	

    set("long",	"这是一张红色的碎纸片，上面还残余着几个字，像是一份礼物单的碎片。");
	set("unit", "张");
	set_weight(1000);
	set("value", 1);

};

ITEM_END;



