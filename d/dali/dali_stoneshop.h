//stoneshop.h

//Sample for room: ʯ��
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_stoneshop);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ʯ��");

	//add npcs into the room
	add_npc("pub_shijiang");
	
	add_door("����Ƕ�", "����Ƕ�", "�����ʯ��");

	set("long", "����ض���һɽʯ������Ȼ�Ļ��ƶ��������£��Ǳ��Ǵ��������Ĵ���ʯ���ô���ʯ�е�ˮī��ʯ�����Ļ�����������̶ȣ�ʹ��̾����ֹ������ʱ���������̽��嶼���Դ���ʯ���ҾӰ��衣ʯ������ͷ�üã��ô���ĥ֮�������ڶ���һ��������ͷ���Ű��ӣ���������С����ָ�����»�ơ�" );

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
