//xin.h 

ITEM_BEGIN(CIxin)

virtual void create(int nFlag = 0)		
{
	 set_name("书信", "guiyun shuxin");
     set_weight(100);
        
     set("unit", "封");
     set("long","这是一封陆冠英写的邀请进入归云庄的书信。");
     set("material", "paper");
};

ITEM_END;
