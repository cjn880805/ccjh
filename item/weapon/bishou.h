//bishou.h

EQUIP_BEGIN(CIBiShou);

virtual void create(int nFlag = 0)	
{
	set_name("ذ��", "bishou");	
	
        set("wield_position", WIELD_HAND);	//modify by lanwood Ӻ��ʹ�õ�ذ�ס�
	set("skill_type", "sword");		
	set_weight(3000);	
	
	set("unit", "��");
	set("long", "ϸ����ذ�ף�������ī���ް�����");
	set("value", 50000);
	set("material", "steel");
	set("no_drop", "�������������뿪�㡣");
	set("no_give", "�����������ܸ��ˡ�");
	set("wield_msg", "$N��ৡ���һ�����һ��$n�������У�ֻ��һ�ɺ������������");
	set("unwield_msg", "$N�����е�$n��ؽ��ʣ�ֻ���͵�һ�����졣");
	
	set("apply/damage", 200);				
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp