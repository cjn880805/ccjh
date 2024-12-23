//bishou.h

EQUIP_BEGIN(CIBiShou);

virtual void create(int nFlag = 0)	
{
	set_name("匕首", "bishou");	
	
        set("wield_position", WIELD_HAND);	//modify by lanwood 雍容使用的匕首。
	set("skill_type", "sword");		
	set_weight(3000);	
	
	set("unit", "柄");
	set("long", "细看那匕首，剑身如墨，无半点光泽。");
	set("value", 50000);
	set("material", "steel");
	set("no_drop", "这样东西不能离开你。");
	set("no_give", "这样东西不能给人。");
	set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中，只觉一股寒气扑面而来。");
	set("unwield_msg", "$N将手中的$n插回剑鞘，只听嗤的一声轻响。");
	
	set("apply/damage", 200);				
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp