// 枯骨刀－－〖血书〗1
// Lanwood 2001-03-14

ITEM_BEGIN(CIbook_kugu_1);

virtual void create(int nFlag = 0)
{
        set_name("空白帐本", "zhang ben");
        set_weight(1000);
        
        set("unit", "本");
		set("long", "一本空白的帐本，跟一般客店里的没什么两样。");
        set("material", "paper");
        set("value", 0l);
		set("name_recognized", "枯骨刀秘笈");
		set("册", 1);
		set("no_drop", 1);
		set("no_put", 1);
        set("skill/name", "kugu_blade");
        set("skill/exp_required", 10000);
        set("skill/sen_cost", 35);
        set("skill/difficulty", 35);
        set("skill/max_skill", 50);
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "study") == 0)
		return do_read(me);
	else if(strcmp(comm, "stain") == 0)
		return do_stain(me);

	return CItem::handle_action(comm, me, arg);
}

virtual int do_look(CChar * me)
{
	CItem::do_look(me);
		
	AddMenuItem("用血浸湿", "$0stain", me);
	SendMenu(me);

	return 1;
}

int do_read(CChar * me)
{
    if (! query("stained"))
    {
        message_vision("$N拿起$n反复研究了一会儿。", me, this);
        tell_object(me, "空白的小册子有什么可看的？");
        return 1;
    }

    return 0;
}


int do_stain(CChar * me)
{
    CContainer * weapon=me->query_weapon();
	char msg[255];
    
	if (!weapon)
        return notify_fail("拿什么来割？");

    if(DIFFERSTR(weapon->querystr("id"), "bi shou"))
        return notify_fail("干嘛？又不是要自杀！还是用匕首吧。");
    
    me->receive_wound("hp", random(me->query("str") * me->query("max_hp") / 100));
    message_vision("$N拿起手中$n，在胳膊上割了个小口子。", me, weapon);
    
    message_vision("$N用伤口的血染红了$n。", me, this);
    tell_object(me, snprintf(msg, 255, "%s上渐渐显出了图形和小字。", name()));
    
	remove_call_out(do_dry);
    call_out(do_dry, 300);
    
	add("stained", 1);
    set_name("〖血书〗", "xue shu");
    set("long", "一本暗红色的小册子，里面写满了蝇头小字。");

    return 1;
}

static void do_dry(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];

    ob->del("stained");
    
	CContainer * where = ob->environment();
	if(userp(where))
		tell_object((CChar *)where, snprintf(msg, 255, "%s渐渐干了，又变回了帐本样子。", ob->name()));
    
	ob->set_name("空白帐本", "zhang ben");
    ob->set("long", "一本空白的帐本，跟一般客店里的没什么两样。");

    return;
}

ITEM_END;