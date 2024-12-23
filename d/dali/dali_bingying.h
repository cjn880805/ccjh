//bingying.h

//Sample for room: ��Ӫ
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_bingying);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ӫ");

	//add npcs into the room
	add_npc("pub_guanbing1");
	add_npc("pub_guanbing1");
	add_npc("pub_guanbing1");
	add_npc("pub_weishi1");

	add_door("�������", "�������", "����Ǳ�Ӫ");
//	add_door("��������", "��������", "����Ǳ�Ӫ");

	set("long", "�������С��ȴ���Ӿ���������Ȼ���˱�����־������������֮�ߣ����ϴ������뱱���γ��޺ͣ�����������£�����ˣ�������ս�¡����ǳ��������Ӫ��Ϊ����ĵ�ϵ��װ�������޲�������ԭ�ط�����ʿ�������Դ�����������������������" );

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
