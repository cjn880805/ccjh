// duanyanqing.c ������

//code by sound
//date:2001-07-12

NPC_BEGIN(CNwanjie_duanyanqing);

virtual void create()
{
        set_name("������", "duan yanqing");
        set("gender", "����");
        set("nickname", "�����ӯ");
        set("age", 45);
        set("long",
                "�������Ĵ����֮�ף��˳ƶ����ӯ�Ķ����ӡ�\n"
                "�����Ǵ�����ϻ��ӣ����ڴ󳼷������Ҷ�˫�Ȳзϡ��\n"
                "��������佭������Ҷ���á���������������ͳ���\n"
                "����ˡ��ڽ����϶˵����޶�����\n"
                "����һ���಼���ۣ����������࣬���ϳ����һ����\n"
                "Ƥ��ߣ�ϲŭ����һ˿��¶������ݳ���˫����ϥ���ϣ�\n"
                "ֻ����Ҹ�µ������������ȴ�������������ɣ����ȳ���\n"
                "���죡\n");
        set("attitude", "peaceful");

        set("str", 60);
        set("int", 35);
        set("con", 35);
        set("dex", 50);
        set("per", 14);
        set("icon",old_man2);

        set("chat_chance_combat", 3);
//	set("chat_msg_combat", ({
//		(: exert_function, "recover" :),
//	}) );
        set("chat_chance", 8);
/*
        set("chat_msg", ({
                "������̾�˿�����������������֪��ʱ�����صǴ���������\n",
                "�������૵�����������������֪�һ��������Ὣ��λ�������ã���������\n",
                (: random_move :),
        }));
*/
        set("hp", 4000);
        set("max_hp", 4000);
        set("mp", 3000);
        set("max_mp", 3000);
        set("mp_factor", 500);

        set("combat_exp", 180000);
        set("shen_type", -1);
        set("score", 18000);

        set_skill("force", 120);
        set_skill("hunyuan_yiqi", 120);
        set_skill("hand", 120);              // �����ַ�
        set_skill("shexing_diaoshou", 120);
        set_skill("dodge", 120);
        set_skill("xiaoyaoyou", 120);        // ��ң��
        set_skill("parry", 120);
        set_skill("staff", 120);
        set_skill("tianshan_zhang", 120);

        map_skill("force", "hunyuan_yiqi");
        map_skill("hand", "shexing_diaoshou");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "tianshan_zhang");
        map_skill("staff", "tianshan_zhang");

        carry_object("gangzhang")->wield();
        carry_object("cloth")->wear();
}

virtual char * chat_msg()		//NPC�Զ�����
{
	switch(random(2))
	{
	case 0:
		return 	"������̾�˿�����������������֪��ʱ�����صǴ���������";
	case 1:
		return 	"�������૵������ε���������֪�һ��������Ὣ��λ�������ã���������";
	}

	return 0;
}
/*
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) )
        {
                remove_call_out("check_skills");
                call_out("check_skills", 2, ob);
        }
}

void check_skills(object ob)
{
        mapping skl;
        object  me;
        string *sname;
        int i, counter, ob_shen;

        me = this_object();
        skl = ob->query_skills();
        sname  = sort_array( keys(skl), (: strcmp :) );
        ob_shen = (int)ob->query("shen");

        counter = 0;
        for(i=0; i<sizeof(skl); i++)
        {
                if (skl[sname[i]] >= 100)
                        counter++;
        }

        if((counter >= 3) && (ob_shen > 0))
        {
                me->set_leader(ob);

                if ( !environment(me)->query("no_fight"))
                {
                        call_out("do_kill", 1, me, ob);
                        return ;
                }
                else
                {
                        call_out("waiting", 0, me, ob);
                        return ;
                }
        }
        return ;
}

int do_kill(object me, object dest)
{
        if( objectp(dest) && present(dest, environment(me))
                 && !environment(me)->query("no_fight"))
        {
                message_vision("$HIR$N��$n˵��������һ�����ɸ��־�������"
                        +RANK_D->query_rude(dest)+"����������$COM\n", me, dest);
                me->set_leader(dest);
                me->kill_ob(dest);
                dest->fight_ob(me);

                call_out("checking", 0,  me, dest);
        }
        else
                call_out("waiting", 1, me, dest);

        return 1;
}

int waiting(object me, object dest)
{
        if ( objectp(dest) )
        {
                if (dest->is_ghost())
                {
                        call_out("do_back", 1, me);
                        return 1;
                }
                else if (me->is_fighting() && present(dest, environment(me)))
                {
                        call_out("checking", 0, me);
                        return 1;
                }
                else if (living(me) && !environment(dest)->query("no_fight"))
                {
                        call_out("do_chase", 0, me);
                        return 1;
                }
        }

        remove_call_out("waiting");
        call_out("waiting", 60, me);
    return 1;
}

int checking(object me, object dest)
{
        object ob;

        if (me->is_fighting())
        {
                call_out("checking", 1, me);
                return 1;
        }

        if( objectp(ob = present("corpse", environment(me)))
                 && ob->query("victim_name") == dest->query("name") )
        {
                call_out("do_back", 1, me);
        return 1;
        }

        call_out("waiting", 0, me, dest);
        return 1;
}

int do_back(object me)
{

        me->move("/d/city/xidajie2");
        message("vision", "���������˹������͵�һ����Ц��˵�����ֳ���һ����ò��Ȼ��α���ӡ�\n",
                environment(), me );

        me->set_leader(0);
        return 1;
}
*/
NPC_END;