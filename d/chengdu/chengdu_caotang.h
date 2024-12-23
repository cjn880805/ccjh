//caotang.h

//Sample for room: �Ÿ�����
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_caotang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�Ÿ�����");

	//add npcs into the room
	add_npc("pub_chaboshi");
	add_npc("pub_duzongqi");
	
	add_door("�ɶ�Ϫ��С·", "�ɶ�Ϫ��С·", "�ɶ��Ÿ�����");

	set("long",	"�����ǶŸ���Ԣ�ɶ��Ĺʾӡ���������ˮ���ӣ�С�Ź���������	��ӳ���Եü�ׯ�����£����ӵ��ţ��ֲ�ʧ����ף��������ʡ�");

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
