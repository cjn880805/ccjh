// zhaocaifeng.c �Կ���-�÷�
// zhangdongni 2001-07-18

NPC_BEGIN(CNcity_zhaocaifeng);

virtual void create()
{

        set_name("�Ծ���", "zhao junrong");
        set("gender", "Ů��");
        set("nickname", "������");
        set("age", 30);
        set("long", "�������ݳ��������Ĳ÷죬�����˳������¡�\n");
        set("attitude", "peaceful");
        set("icon", young_woman4);
                     
        set("str", 20);
        set("int", 20);
        set("con", 24);
        set("dex", 20);

        set("mp", 500);
        set("max_mp", 500);
        set("hp", 120);
        set("max_hp", 120);
        set("mp_factor", 50);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set_skill("force", 50); 
        set_skill("unarmed", 50); 
        set_skill("dodge", 50); 
        set_skill("parry", 50);          

 /*       set("inquiry", ([
                "����" : (: do_gongzuo :),
        ]) );

        
        carry_object("cloth")->wear();
}
int do_gongzuo()
{      
        object me;
        me = this_player(); 
        if (me->query("combat_exp")>=10000)
        {
               command("say ����书���Ҷ���Ҷ����Ҫ���ˣ�����С�²�������ܡ�\n");
               return 1;
         }
    if( me->query_temp("gongzuo/yunbu")>0)
    {
                tell_object(me,"��ȥ�Ѳ�ƥ�ٺú󽻸��Ұɡ�\n");
                return 1;
    }  
    message_vision(CYN"�Կ��ݶ�$N˵���������ٺõĲ�ƥ�������ˣ���͵�����Ŀⷿ��ȥ��Щ������\n"NOR,me); 
        me->set_temp("gongzuo/yunbu", 1);
        return 1;   
}
int accept_object(object me, object ob)
{
        object ob1;
        if (strsrch(ob->query("name"), "�ٺõĲ�") < 0) 
        {
            command("say ������������������ٺõĲ���\n");
        }
        else if (me->query_temp("gongzuo/yunbu")<1)
        {
         command("say ��û�н�������ٲ�ѽ��\n");
        }
        else
        {
    message_vision(CYN"�Կ��ݶ�$N˵���������ˣ�������Ĺ�Ǯ��\n"NOR,me);
    message_vision(CYN"�Կ��ݵݸ�$NһЩͭǮ��\n"NOR,me);  
                me->delete_temp("gongzuo/yunbu");
                me->add("combat_exp",20+random(20));
                me->add("potential",10+random(10));
                ob1=new("/clone/money/silver");
                ob1->move(me); 
    call_out("destroying", 1, this_object(), ob);
            return 1;
        }
    return 0;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
*/
}
NPC_END;
