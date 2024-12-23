//shantang.h

//Sample for room:  ����������
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_shantang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");

	add_door("������", "������", "����������");
	add_npc("quanzhen_zhangyao");

	set("long", "������ȫ��̵����ã��ǵ������ò͵ĵط�������úܴ�����ذڷ���һ��һ�ŵ����Ρ�������������������������ȫ����ӣ��е������òͣ��еĵ�ͷ̸Ц�����ſɿڵķ��ˣ����̲�סҲ���(order)һ�ݡ�");

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
//last, register the room into ../server/RoomSetup.cpp