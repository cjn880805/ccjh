//ytjian.h

//Sample for ITEM: ���콣
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIytjian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���콣");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(20000);		//set item weight
	
	set("unit", "��");
	set("value", 5000000);
	set("material", "steel");
	set("long", "����һ���ĳ������ĹŽ��������Ͻ�˿���������֡����족������������������һ����������δ���ʣ��ѿɼ��䲻����");
   	set("wield_msg","ֱ�������ˮ���������һ�㣬$n����$N���У����Ϊ֮��ɫ��");
   	set("unwield_msg", "$N��$n������䣬�����������ؼ�ֻ��������");
	set("unequip_msg",  "���콣����һ���׹⣬��ৡ��ط��뽣�ʡ�" );
	//	init_sword(1000);
	set("apply/damage", 1000);					//set the modifiers of attribute
	
	set("no_drop", "��˱���������������󰡡�");
	set("no_give", "���ˣ�������ĳ�����");
	set("no_put", "��ϧ���ɡ�");
	set("no_duo",1);//�����Զ���

//	call_out(do_die, 5);	
	
};

virtual void owner_is_killed(CChar * killer)
{
	destruct(this);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	if(!ob->query_temp("save"))//save---����ʹ��
		destruct(ob);
	else
		ob->call_out(do_die, 3600);
}

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp



