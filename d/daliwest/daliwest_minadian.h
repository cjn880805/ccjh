//minadian.h

//Sample for room: ���ɵ�
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiWest_minadian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ɵ�");

	set("resident", "����");

	//add npcs into the room
	add_npc("pub_shaonu");
	
	add_door("����Ǹ�³��", "����Ǹ�³��", "��������ɵ�");

	set("long", "���������ķ�֧�����������۾ӵ����ӣ����������ɵ�����ݡ�������Ϫ��������ˮ������ı��������ũҵ��Թ������������Ϸ�����о���Щ��ª����ӣ�Ҳ�������̹�����" );

};

RESIDENT_END;
