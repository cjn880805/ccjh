//daodian.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_daodian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	//add npcs into the room
	add_npc("pub_daodianhuoji");/////////////////////////

	add_door("������", "������", "���ݵ���");

	set("long", "����һ�����������ز���Ӣ������С�������ı����̣��ϰٰѸ�ʽ�����ġ�Ӣ������С����������İڷ��ڹ�̨�ϣ�˵��С��ȴ�ߴ����ƴ���ͬ�����г���һ�����Ҷ�ɵ���Ҳ�г������ߵİ������䵶�����Ļ��ǳ����磬�����֣�����һ���б���ֽ��ذ�׹�̨�����ǽ��Ҳ����Щ�������ֵ������ȵ���ԭ������");  

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
