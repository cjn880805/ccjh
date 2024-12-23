//chunyangdian.h

//Sample for room:  ���Ҵ�����
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_chunyangdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���Ҵ�����");
	
	add_npc("pub_nigu2");           // add by zdn 2001-07-14

	add_door("���ҹ��Ƹ�", "���ҹ��Ƹ�", "���Ҵ�����");
	add_door("������ˮ��", "������ˮ��", "���Ҵ�����");

	set("long","�������һǧ���ף������ľ�Դ䣬�ľ����ˡ���ǰ��һʯ��������ʯ����˵����������ɽʱ������������Ϣ�����ڴ˿��ݹ۶�����壬�����𶥣������ͱڣ�������ߡ�������������ˮ�֣������ǹ��Ƹ�");
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
