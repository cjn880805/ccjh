// chen.c  陈有德
//zhangdongni 2001-07-17

NPC_BEGIN(CNyangzhou_chen);

virtual void create()
{
        set_name("陈德有", "chen youde");
        set("long", "陈有德是扬州武馆馆长。");
        set("gender", "男性");
        set("age", 45);
  	    set("nickname", "德哥");
	    set("icon", young_man2);
	
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("claw", 80);
        set_skill("hand", 80);
        set_skill("strike", 80);
        set_skill("finger", 80);
        set_skill("cuff", 80);
        set_skill("blade", 80);
        set_skill("stick", 80);
        set_skill("club", 80);
        set_skill("staff", 80);
        set_skill("sword", 80);
        set_skill("throwing", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
       

}
/*
int accept_object(object who, object ob)
{
    if (who->query("combat_exp")>= 10000)
    {
        message_vision("陈有德望着$N说：你的武功应该历练江湖才能再长进，不能埋没
在这里了。\n", who);
        return 0;
    }
    if (ob->query("money_id") && ob->value() >= 500)
    {
        who->set_temp("marks/yangzhou_paied",1);
        message_vision("陈有德对$N说：好！这位" + RANK_D->query_respect(who) 
+ "想学什么呢？\n" , who);
        return 1;
    }
    else
        message_vision("陈有德皱眉对$N说：钱我不在乎。可你也给的也太少了点儿吧？\n", who);
        return 0;
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("marks/yangzhou_paied")==1) return 0;
        return 1;
}
*/
NPC_END;

