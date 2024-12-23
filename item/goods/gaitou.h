//gaitou.h
//大红盖头
//Lanwood 2001-03-17

EQUIP_BEGIN(CIgaitou)

virtual void create(int nFlag = 0)		
{
	set_name("大红盖头", "gai tou");
           
	set("wield_position", WIELD_HEAD);	
 	set_weight(2000);	

	set("apply/name", "新娘子");
	set("apply/title", "害羞的");
	set("apply/id", "marry girl");
	set("apply/long", "这是一个等待丈夫为她揭开盖头的羞答答的新娘子。");

	set("long",	"这是给新娘子专用的大红盖头。");
	set("unit", "块");
	
	set("value",500);
};

virtual int Do_Action(int nAct, CChar * me = NULL)
{
	CContainer * owner =  environment();
	
	if(!owner) return 0;

	if(nAct == DO_WIELD && Query(CAN_EQUIPPED))
	{			
		if(! Do_Wield()) return 0;
		//owner->set_temp("apply/icon", query("apply/icon"));
		owner->UpdateMe();
		return 1;
	}
	else if(nAct == DO_UNWIELD)
	{
		if(! Do_UnWield()) return 0;
		owner->delete_temp("apply/icon");
		owner->delete_temp("apply/title");
		owner->UpdateMe();
		return 1;
	}

	return CEquip::Do_Action(nAct, me);
}

EQUIP_END;
