//jiasha.h

//Sample for ITEM: ����
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIjiasha);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(800);		//set item weight

	set("long", "һ���ɵ��Ѿ���������ɫ�����ģ������кö������");
	set("unit", "��");
	set("material", "cloth");
	set("no_get", "�������������뿪�Ƕ���");
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "move") == 0)
	{
		return do_move(me);
	}

	return 0;
}

int do_move(CChar * me)
{
	if (me->query("passwd") )
	{
		if (!me->PresentName("kuihua_baodian", IS_ITEM))
		{
			message_vision("$N�����Ų�����ģ�����һЩ����...��ͻȻ�����ĵĿ����й���һ���鵽$N���С�", me);
			CContainer * book = load_item("kuihua");
			book->move(me);
			return 1;
		}
		
		message_vision("$N�����Ų�����ģ�����һЩ������Ǻ��$Nֱ�����硣", me);
		return 1;
	}
	else 
	{
		message_vision("$N�����Ų�����ģ�ͻȻ�����ĵĿ�����ð��һ�ɶ��������$N�ı����С�", me);
		me->die();
		if(random(2))
			destruct(this);
		return 1;
	}
}

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp