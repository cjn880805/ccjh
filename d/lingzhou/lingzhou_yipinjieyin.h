//yipinjieyin.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_yipinjieyin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");
	
	add_npc("lingzhou_nuerhai");             //add by zdn 2001-07-14


	add_door("����һƷ�ô���", "����һƷ�ô���", "���ݽ�����");

	set("long", "����������һƷ�õĽ����ã�ÿ����Ը����һƷ�õĽ������֣��������˳䵱�����ˣ������ϸ���������á������Ժ󣬲����ʸ��ɺ������ܷ�������ΪһƷ��Ч�������������и�רְ�����ĺ��ӣ�ΪһƷ�ù㿪��·������һƷ���ڽ�����Ҳȷʵ����ȸ��");  

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
