//neiting.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_neiting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	add_npc("dali_duanzc");	
	add_npc("dali_guducheng");	
	add_npc("zm_dali");	

	add_door("�������������", "�������������", "�������������");
	add_door("�������������", "�������������", "�������������");
	add_door("����������鷿", "����������鷿", "�������������");

	set("long", "������������������������������ʮ�ֿ�������˵��������������ܼ򵥣����м�������̫ʦ�Σ����ϰ����˸��ָ�����ɽ�軨��" );
	

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;
