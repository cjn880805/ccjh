//jianchuan.h

//Sample for room: ����ǽ�����
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_jianchuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ǽ�����");

	set("resident", "������");

	//add npcs into the room
	add_npc("pub_lieren");
	add_npc("pub_pihuoshang");

	add_door("����ǽ���ɽ��", "����ǽ���ɽ��", "����ǽ�����");
	add_door("����ǲ�ɽ�в�", "����ǲ�ɽ�в�", "����ǽ�����");

	set("long", "�����ǽ����������ģ����Ӳ��󣬾�����󲿷��������壬����ȫ��������Ϊ��������ɽ�ߵغ�������ɽ�ֵ�Ұ�޴��Ƥ��ë���в���Ƥ����������͵������˽��ס�����ɽ��������������Ҳ������֮;���ϴ���ɽ��ɵִ�����½��");
};

RESIDENT_END;
