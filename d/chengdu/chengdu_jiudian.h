//jiudian.h

//Sample for room: �񶼾�¥
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_jiudian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�񶼾�¥");

	//add npcs into the room
	add_npc("pub_tanghua");/////////////////////////
	add_npc("pub_xiaoer2");


	add_door("�ɶ���", "�ɶ���", "�ɶ��񶼾�¥");

	set("long",	"����һ����������������Ĵ��¥����˵���ϵ���������ȴҲ���ɲ��������������Ϲ���һ�������ң���д�š��񶼾�¥���ĸ�������֡�¥�������ξ������п������κ��ݣ�ʮ���Ǹ��̴�֡�����һ�Ұ����ϵ꣬�������ڵ���λ�ƹ��Ѿ��ǵ��Ĵ�����˵���ᶽ�����е㲻�����ȴҲ����������¥���ս����𡣶��Ͻ���һ������ͨ��¥������������������Գ�������֡�"	);

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
