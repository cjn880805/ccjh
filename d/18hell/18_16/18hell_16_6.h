//18hell_16.h
//ʮ�˵�����ʮ�������Ե�����6����

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_16_6);

virtual void create()			//Call it when Room Create
{
	set_name("���Ե���");
	
	add_npc("diyu_shizhe16");

};

virtual int do_look(CChar * me)
{
	say("����ǰһ�޹�����һ���ˣ���һ��ʯ�Ͻ������ӽ����У����ܸ�ǽ��������ǽ����ľ׮���ɵ���Ȧ��Ȧ�У�ţ�����������ǡ���������ʨ�ȶ�������˺ҧ��ʳ���ˣ���֫�����ȡ���ͷ���Ѷǣ�����ʹ���쳣��", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
