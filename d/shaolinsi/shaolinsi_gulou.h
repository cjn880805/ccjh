//gulou.h

//Sample for room: ��¥СԺ
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_gulou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��¥СԺ");

	add_npc("shaolin_qing_wen");

	add_door("�����¾�����", "�����¾�����", "�����¹�¥СԺ");

	set("long", "����һ��שľ�ṹ�ı����������߲㣬�������˽��Σ��������ᣬ�ܽ��Ϲ�����һ����Сͭ�壬��綣�����졣����ǽ���οյ�������������ǵ�����һ������̬άФ��������������֮�֡�������ڴ�����һ�ȹ��ε�Сľ�ţ����������ò���Ϳ�棬��������������ɽ�������ڷ𽲾�ʱ�����Ρ�" );

};


ROOM_END;
