//frog.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_frog);

virtual void create()
{
	set_name("������","frog");

    set("age", 7);
    set("long", "����һֻ��˿�����ܣ���������յ�ˮ̶�ȫ�������ʷ�׳׳��һ��Ѫ����۾���ʮ�ֶ��ģ�������ɱ������");

	CVector v;

	v.append("bite");
	set("verbs", v);

    set("combat_exp", 50);
    set("shen_type", -1);
    set("str", 11);
    set("dex", 11);
    set("con", 11);
    set("int", 11);
    set("attitude", "peaceful");
}


virtual char * greeting(CChar * player)
{
    return "���������ɽ���������һ�������ֻ��ĵ���ģ����";
}

/*
virtual int handle_action(char * comm, CChar * player , char * arg)
{
	if(strcmp(comm,"dajia"))
		return do_dajia(player);
	else if(strcmp(comm,"save"))
		return do_save(player);
	else if(strcmp(comm,"drop"))
		return do_drop(player);
	return 0;
}

int do_dajia(CChar * player)
{
    say ("���ﶼ��ˮ��վ��վ���ȣ�����ʲô��ʡ�������գ�",player);
    return 0;
}

int do_save(CChar * player)
{
    say ("����̣�ʡ�������գ�",player);
    return 0;
}
int do_drop(CChar * player)
{
    say(" �Ҷ��������ȼ�������",player);
    return 0;
}
*/

NPC_END;
