//tuyaoguan.h
//Sample for room: ��Ҥ��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuanWai_tuyaoguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room

	set_name( "��Ҥ��");
	
	add_npc("pub_dibao");
	add_npc("pub_genu");
	add_npc("pub_xiaoer2");                   // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("������Զ", "������Զ", "������Զ��Ҥ��");

    set("long","һ�������С����һ��֬�ۻ���Ŵ����ζ���˱Ƕ�����������Ǻ��һ����ͷ�����ڵ��źܶ�����͵��������ı��յ�ͨ�졣�ܶഩ�����õĺ��ӣ�һ��§�Ź��һ�����žƺ������ڸ�̸���ۡ�һ�����ֵ���ѻһ���д��ſ��ˣ�һ������ߴٵ�����İ鵱�͹����ǡ�" );

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
