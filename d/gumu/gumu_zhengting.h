//zhengting.h

//Sample for room: ��Ĺ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_zhengting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ĺ����");

	//add npcs into the room
	add_npc("gumu_longnv");
	
	add_door("��ĹС��", "��ĹС��", "��Ĺ����");
	add_door("��Ĺ����", "��Ĺ����", "��Ĺ����");
	add_door("��Ĺ������", "��Ĺ������", "��Ĺ����");

    set("long","�����ǹ�Ĺ������������Ӧ��ͣ�����ѹ�ľ֮��Ķ�����ȴ��֪�����˰㵽����ȥ�ˡ������ж�����һλ������Ů�������ϰڷ���һ��ʯͷ���ɵĴ�(chuang)�����к�ϵ��һ�����ӣ���֪����ʲô�õģ�����֮�⣬���ް��衣" );
	
	set("valid_startroom",1);
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
