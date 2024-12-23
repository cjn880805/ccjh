ITEM_BEGIN(CIletter)

virtual void create(int nFlag = 0)		
{
	set_name("手信", "hand letter");
    set_weight(100);
        
    set("unit", "封");
    set("long", "这是华山派掌门岳不群的手信，请冯铁匠把打好的宝剑交给执信弟子。");
    set("material", "paper");
};

ITEM_END;
