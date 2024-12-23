//gongpingziw.h
//code by zwb
//12-25


NPC_BEGIN(CNpub3_gongpingziw);


virtual void create()
{

	set_name("��ƽ��","gong ping zi");

	set("icon", taoist_with_sword);
	set("gender", "����");
	set("age", 35);
	set("long","����һλ�ɷ���ǵ�������ˣ����������ķ����Ժ�������������˽��");

	set("combat_exp",60000);
    set("shen_type", 1);
	set("attitude", "friendly");

	set("apply/attack", 50);
	set("apply/defense", 50);

	set("max_hp", 2400);
	set("max_mp", 800);

	set("win_times", 0l);

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("sword",80);
	set_skill("parry",80);
	set_skill("dodge", 80);
//	set_inquiry("������",ask_me);

  
//    carry_object("cloth")->wear();
    carry_object("changjian")->wield();
}


/*

static char *  ask_me(CNpc * npc , CChar * player)
{
        object* ob;
        int i;
        ob = users();

        if ( !wizardp(player)) return "����Ȩ�ٿ������ᣡ\n";

        for ( i=sizeof(ob); i>0; i-- ) {
                if (environment(ob[i-1]))
                {
                        ob[i-1]->move("/d/city/wudao1");
        		ob[i-1]->set_temp("view_leitai",1);
                }
        }

        return "�ã����ڱ�������ʽ��ʼ��ȫ�弯�ϣ�\n";
}

int do_no()
{
        command("say " + "������Ŀ���������˲���֮�¡�\n");
        return 1;
}
int do_start()
{
        int i,j;
	object *allob, ob1, ob2, old_target, where;

        if (!wizardp(this_player()))
        {
             command("say " + "����Ҫ��ʦ����ſ�ʼ��\n");
             return 1;
        }
        allob = all_inventory(environment(this_player()));
        ob1 = this_object();
        ob2 = this_player();

        j = 0;
        for ( i=sizeof(allob); i>0; i-- ) {
             if ( userp(allob[i-1]) &&
                 !wizardp(allob[i-1]))
             {
                if (j == 0)
                {
                    ob1 = allob[i-1];
                    j = 1;
                }
                else ob2 = allob[i-1]; 
             }
        }
        if (ob2 != this_player()) ob1->fight_ob(ob2);
        if (ob1 == ob2) return notify_fail("ֻ��һ���˲��ܱ��䡣\n");


        ob1 = this_player();

        if ( this_object()->query_temp("busy") )
                return notify_fail("ÿ��ֻ�������˲μӱ��䡣\n");

        if (!ob2 = present(arg,environment(ob1)) )
                return notify_fail("�����˭�Ȼ���\n");
        if (ob1 == ob2)    return notify_fail("ֻ��һ���˲��ܱ��䡣\n");

        if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
                message_vision("\n$N����$n˵����"
                        + RANK_D->query_self(ob1)
                        + ob1->name() + "�����"
                        + RANK_D->query_respect(ob2) + "�ĸ��Т�\n\n", ob1, ob2);
                if( objectp(old_target = ob1->query_temp("pending/fight")) )
                        tell_object(old_target, YEL + ob1->name() + "ȡ���˺�����Ե���ͷ��\n" NOR);
                ob1->set_temp("pending/fight", ob2);
                tell_object(ob2, YEL "�����Ը��ͶԷ����б��Ԫ�����Ҳ��" + ob1->name() + "("+(string)ob1->query("id")+")"+ "��һ�� bihua ָ�\n" NOR);

                write(YEL "��춶Է�������ҿ��Ƶ����窱�����ȶԷ�ͬ����ܽ��б��ԡ�\n" NOR);
                return 1;
        }

        ob1->delete_temp("halted");
        ob2->delete_temp("halted");

        remove_call_out("check");
        call_out("check",0, ob1, ob2);

//      ob1->set("qi",(int)ob1->query("max_qi"));
//      ob2->set("qi",(int)ob2->query("max_qi"));

        remove_call_out("fighting");
        call_out("fighting",2, ob1, ob2);

        return 1;
}
int do_bihua(string arg)
{
        object ob1, ob2;
        object old_target;

        ob1 = this_player();

        if( !arg || arg=="" ) return 0;

        if ( arg == "gongping zi" || arg == "zi" || arg == "referee" )
        {
             command("say " + "�㲻�ܸ��ұȻ���\n");
             return 1;
        }

        if ( this_object()->query_temp("busy") )
                return notify_fail("ÿ��ֻ�������˲μӱ��䡣\n");

        if (!ob2 = present(arg,environment(ob1)) )
                return notify_fail("�����˭�Ȼ���\n");
        if (ob1 == ob2)    return notify_fail("�㲻�ܹ����Լ���\n");
	if (ob1->query("max_qi") > ob1->query("qi"))
                return notify_fail("������̫�ت����ܱ��䡣\n");
	if (ob1->query("max_qi") > ob1->query("eff_qi"))
                return notify_fail("������̫�ت����ܱ��䡣\n");
	if (ob2->query("max_qi") > ob2->query("qi"))
                return notify_fail("�Է�����̫�ت����ܱ��䡣\n");
	if (ob2->query("max_qi") > ob2->query("eff_qi"))
                return notify_fail("�Է�����̫�ت����ܱ��䡣\n");
 ��������Ա�
        command("say " + "����Ҫ���з���ſ�ʼ��\n");
        return 1;


        if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
                message_vision("\n$N����$n˵����"
                        + RANK_D->query_self(ob1)
                        + ob1->name() + "�����"
                        + RANK_D->query_respect(ob2) + "�ĸ��Т�\n\n", ob1, ob2);
                if( objectp(old_target = ob1->query_temp("pending/fight")) )
                        tell_object(old_target, YEL + ob1->name() + "ȡ���˺�����Ե���ͷ��\n" NOR);
                ob1->set_temp("pending/fight", ob2);
                tell_object(ob2, YEL "�����Ը��ͶԷ����б��Ԫ�����Ҳ��" + ob1->name() + "("+(string)ob1->query("id")+")"+ "��һ�� bihua ָ�\n" NOR);

                write(YEL "��춶Է�������ҿ��Ƶ����窱�����ȶԷ�ͬ����ܽ��б��ԡ�\n" NOR);
                return 1;
        }

        ob1->delete_temp("halted");
        ob2->delete_temp("halted");

        remove_call_out("check");
        call_out("check",0, ob1, ob2);

//      ob1->set("qi",(int)ob1->query("max_qi"));
//      ob2->set("qi",(int)ob2->query("max_qi"));

        remove_call_out("fighting");
        call_out("fighting",2, ob1, ob2);

        return 1;

}

void fighting(object ob1, object ob2)
{
        ob1->fight_ob(ob2);
        ob2->fight_ob(ob1);
}

void check(object ob1, object ob2)
{
        this_object()->set_temp("busy",1);
        command("chat " + ob1->query("name")
                + "��" + ob2->query("name") + "��������̨�Ͽ�ʼ�����˧��\n");
        call_out("observe",1,ob1,ob2);
}

int observe(object ob1,object ob2)
{
        object ob;

        if(ob1->is_fighting())
        {
                call_out("observe",1,ob1,ob2);
                return 1;
        }

        this_object()->delete_temp("busy");
        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");

        if ( !present(ob1, environment()) )
        {
                command("chat " + ob1->query("name") + "��������̨�ˣ�\n");
                command("chat " + ob1->query("id") + "��������̨�ˣ�\n");
                return 1;
        }

        if ( !present(ob2, environment()) )
        {
                command("chat " + ob2->query("name") + "��������̨�ˣ�\n");
                command("chat " + ob2->query("id") + "��������̨�ˣ�\n");
                return 1;
        }

        if (ob1->query_temp("halted"))
         {
                ob1->delete_temp("halted");
                command("chat " + ob1->query("name") + "��;�������䣡\n");
                command("chat " + ob1->query("id") + "��;�������䣡\n");
                return 1;
         }
        if (ob2->query_temp("halted"))
         {
                ob2->delete_temp("halted");
                command("chat " + ob2->query("name") + "��Ը���������ˣ�\n");
                command("chat " + ob2->query("id") + "��Ը���������ˣ�\n");
                return 1;
         }

        if ( ob1->query("qi")*2 > ob1->query("max_qi"))
        {
                if  (ob2->query("qi")*2 > ob2->query("max_qi")) {
                        command("chat " + ob1->query("name")
                                + "��" + ob2->query("name") + "���䲻��ʤ����\n");
                        return 1;
                }
                command("chat " + ob1->query("name")
                        + "����սʤ" + ob2->query("name") + "��\n");
                command("chat " + ob1->query("id")
                        + "����սʤ" + ob2->query("id") + "��\n");
                ob = new("clone/money/silver");
                ob->move(ob1);
        }
        else
        {
                command("chat " + ob2->query("name")
                        + "����սʤ" + ob1->query("name") + "��\n");
                command("chat " + ob2->query("id")
                        + "����սʤ" + ob1->query("id") + "��\n");
                ob = new("clone/money/silver");
                ob->set_amount(2);
                ob->move(ob2);
        }

        return 1;

}

int do_halt()
{
	object me = this_player();
	if (me->is_fighting()) me->set_temp("halted",1);
	return 0;
}*/

NPC_END;