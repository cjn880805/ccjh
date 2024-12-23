//hcazhengdian.h

//Sample for room:  ���һ���������
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcazhengdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���һ���������");

	add_npc("pub_guest");
	add_npc("emei_xin");

	add_door("���һ�����", "���һ�����", "���һ���������");
	add_door("���һ����������", "���һ����������", "���һ���������");
	add_door("���һ����ֶ����", "���һ����ֶ����", "���һ���������");
	add_door("���һ����ֹ㳡", "���һ����ֹ㳡", "���һ���������");

	set("long","�����Ƕ���ɽ�𶥻����ֵ���������ֹ�ģ��󣬵�����ש�̵أ��м��������������������������ǰ����һ��ľ���������������Թ�ߵ�ݡ��Դ����Ҹ���һ����ǽӴ���͵ĵط���������ͨ��һ����㳡��ֻ�ж��ҵ��Ӳ��ܹ�ȥ��");
    
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
