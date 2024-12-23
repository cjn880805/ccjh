//longmen.h

//Sample for room: ���ŷ�
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_longmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ŷ�");
	
	add_npc("pub_old");     // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("�������", "�������", "�������ŷ�");
	add_door("����¹����", "����¹����", "�������ŷ�");
	add_door("��������", "��������", "�������ŷ�");
	add_door("�����ͷɽ���1", "�����ͷɽ���1", "�������ŷ�");

    set("long","���ŷ��ڳ�鶺���������״�����Σ��������š����¾��ڣ���̬���أ�����������ˮ����˵������ˮ�����˷壬���������ʯ����" );
    

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
