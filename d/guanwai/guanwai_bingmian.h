//bingmian.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_bingmian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	set("monster_chance", 50);
	
	add_npc("guanwai_diyun");    //add by zdn 2001-07-20

	add_door("���⴬��", "���⴬��", "�������");
	add_door("������ſ���", "������ſ���", "�������");

    set("long","�������ɻ����Ľ��棬���Ѷ����˼��ߺ�ļ�������˻���ƥ���������ɺ��⽭�������Σ�ա����������к��Ļ�ѩ������������һƬ��ֻ���м侭������֮����¶��һ����ɫ�ı�·��" );
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
