//zongtong.h
//Sample for room: ̨����ͳ��

//coded by Teapot

//data: 2000-11-4



ROOM_BEGIN(CRTaiWan_zongtong);



virtual void create()			//Call it when Room Create
{
	set_name( "̨����ͨ��");

	set("monster_chance", 20);

	add_door("̨�����Ժ", "̨�����Ժ", "̨����ͨ��");
	add_door("̨����ҩ������", "̨����ҩ������", "̨����ͨ��");
	add_door("̨���һ�Ժ", "̨���һ�Ժ", "̨����ͨ��");

	set("long", "�򹷸�λ��̨���ϲ��������С�������е����������ھ�����Ͽ�壬��ǫ̈̄��һ���ۡ�  " );
};

ROOM_END;
