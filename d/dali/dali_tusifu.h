//tusifu.h

//Sample for room: ��˾��
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_tusifu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��˾��");

	//add npcs into the room
	add_npc("dali_datusi");/////////////////////////
	add_npc("pub_shicong");

				

	add_door("�������", "�������", "�������˾��");

	add_door("�������˾��������", "�������˾��������", "�������˾��");

	set("long", "��˾���ǵ��ش�����Ϯ��˾���ϵ����ţ�һ�����ϵ�שľ�������ͥ�Ӹ����£�ׯ�ϼ�ʵ����ǰ�ǿ���ʯ�ף��е����������ƣ����ݹ���̨��ռ��Լ�˰�Ķ���������������������������᷿��" );

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
