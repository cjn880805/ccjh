//zhenxiong.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiWest_zhenxiong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	set("resident", "����");

	//add npcs into the room
	add_npc("pub_muyangnu");/////////////////////////
	add_npc("pub_wyshangfan");
	add_npc("baiyang");
	
	add_door("���������", "���������", "���������");
	add_door("����ǰ͵ĵ�", "����ǰ͵ĵ�", "���������");
	add_door("����Ǹ�³��", "����Ǹ�³��", "���������");
	add_door("������������", "������������", "���������");

	set("long", "�������������ľ۾����ģ�������������Ĵ󲿣������ģ����а͵ĵ顢���ۡ��͸���������������һ��ʯ��С�ǣ��˿ڲ��࣬����ɢ�������Ӹ�������������Ҫ��һЩ���̺ͼ�������" );

};

RESIDENT_END;
