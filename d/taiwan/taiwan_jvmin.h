//jvmin.h
//Sample for room: ̨����ҩ������

//coded by Teapot

//data: 2000-11-4



ROOM_BEGIN(CRTaiWan_jvmin);



virtual void create()			//Call it when Room Create
{
	set_name( "̨����ҩ������");

	set("monster_chance", 20);

	add_door("̨������Ժ", "̨������Ժ", "̨����ҩ������");
	add_door("̨������Ժ", "̨������Ժ", "̨����ҩ������");
	add_door("̨����ͨ��", "̨����ͨ��", "̨����ҩ������");

	add_door("̨��ĵ�", "̨��ĵ�", "̨����ҩ������");

	set("long", "�򹷸�λ��̨���ϲ��������С�������е����������ھ�����Ͽ�壬��ǫ̈̄��һ���ۡ�  " );
};

ROOM_END;
