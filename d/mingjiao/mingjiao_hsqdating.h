//hsqdating.h



//Sample for room: ��ˮ�����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_hsqdating);

virtual void create()			//Call it when Room Create
{

	set_name( "���̺�ˮ�����");

	add_npc("mingjiao_tangyang");
	add_npc("pub_huiyue");
	
	add_door("������ʯ���6", "������ʯ���6", "���̺�ˮ�����");

	set("long", "�����Ǻ�ˮ��Ĵ����������ı���ī��������̨�ξ�Ϊ��ɫ��ǹҷ��ӧ���������룬���õ���Įɭ�ϡ���������в輸����ˮ������ʹ����������������ɱ����" );

};

ROOM_END;
