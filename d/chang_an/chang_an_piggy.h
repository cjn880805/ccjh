//piggy.h

//Sample for room: ��������
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_piggy);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");


	add_door("����������", "����������", "������¥����");

	set("long", "��䷿����ר��Ϊ�˹����ö���ģ��������Ӷ����ò�ȥƤ��������ɡ�һ��ʯ�� (table)��Χ�����ĸ�ʯ�⣬��������һ�����ʯ������ȥ��Ϊ�⻬���ıڹ��ų����ƣ��������յ�������硣ǽ��������һ¯��֪�����㣬�ƺ���������֮Ч����¯�Ա߹����Ÿ�ʾ(gaoshi)������д������Ĺ�أ���������Сֽ��(note)������ݲݵļ��Ź���ɼ��� " );

    set("no_fight",  1);
    set("no_magic",  1);

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

CHANGAN_END;
