//frog.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_frog);

virtual void create()
{
	set_name("大青蛙","frog");

    set("age", 7);
    set("long", "这是一只黑丝大青蛙，长在深不见日的水潭里，全身恶臭，肥肥壮壮，一对血红的眼睛，十分恶心，你真想杀了它。");

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
    return "大青蛙呱呱叫了两声，一副幸灾乐祸的得意模样。";
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
    say ("这里都是水，站都站不稳，还打什么打？省点力气罢！",player);
    return 0;
}

int do_save(CChar * player)
{
    say ("想存盘？省点力气罢！",player);
    return 0;
}
int do_drop(CChar * player)
{
    say(" 乱丢垃圾？先捡起来！",player);
    return 0;
}
*/

NPC_END;
