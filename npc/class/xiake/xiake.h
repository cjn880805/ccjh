//xiake.h

#define XIAKE_BEGIN(npc_name)	class npc_name : public CNxiake	{	public:	npc_name(){};	virtual ~npc_name(){};
#define XIAKE_END		};	

NPC_BEGIN(CNxiake);

static char *  ask_zhou(CNpc * npc , CChar * player)
{
	return "这是本岛特有的东西，它主要由一味'断肠独骨腐心草'构成,要开花后效力方著，但这种草每十年才开一次花，所以腊八粥很名贵，一般人很难得到的，小兄弟想要就要看你的缘分了！";
}

virtual int accept_object(CChar * player , CContainer * ob)
{
        CContainer * obn;

        if (  DIFFERSTR(ob->querystr("id"), "shane bu") && DIFFERSTR(ob->querystr("id"), "fuxin cao"))
        {
			say("这不是我想要的呀！",player);
			SendMenu(player);
            return 0;
        }

        if ( EQUALSTR(ob->querystr("id"), "shane bu" ))
        {
		    if(query_temp("cao"))
            {
				destruct(ob);
				message_vision("恭喜这位小兄弟了!",player);
                obn=load_item("zhou");
                obn->move(player);
                delete_temp("bu");
                delete_temp("cao");
                return 1;
            }
		    else if(query_temp("bu"))
			{
			    say("赏善罚恶簿我有了。",player);
			    SendMenu(player);
			    return 0;
			}
		    else
			{
				destruct(ob);
				say("现在只差腐心草了。",player);
				SendMenu(player);
				set_temp("bu",1);
				return 1;
			}
        }

        if ( EQUALSTR(ob->querystr("id"), "fuxin cao"))
        {                
			if(query_temp("bu"))
            {
				destruct(ob);
                say("恭喜这位小兄弟了!",player);
				SendMenu(player);
                obn=load_item("zhou");
                obn->move(player);
                delete_temp("cao");
                delete_temp("bu");
                return 1;
            }
            else if(query_temp("cao"))
            {
                say("腐心草我已经有了。",player);
				SendMenu(player);
                return 0;
            }
            else
            {
				destruct(ob);
                message_vision("现在只差赏善罚恶簿了。",player);
                set_temp("cao",1);
                return 1;
            }           
        }

        return 1;
}

virtual void attempt_apprentice(CChar * player)
{
    message_vision("$N摇了摇头。",player);
    say("我是不收弟子的，你可以到石室中自学哇！");    
}

NPC_END;
